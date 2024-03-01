#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>


template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

 std::vector<T> items_;
 int m_;
 PComparator c_;

 void trickleup();

 void trickledown();


};

// Add implementation of member functions here

// Your code here

template <typename T, typename Comparator>
Heap<T,Comparator>::Heap(int m, Comparator c) :
m_(m), c_(c){
  if(m_<2){
    throw std::invalid_argument("Heap has to be at least 2-ary");
  }
}

template<typename T, typename Comparator>
Heap<T,Comparator>::~Heap(){
  // while(!items_.empty()){
  //   items_.pop_back();
  // }
}


template<typename T, typename Comparator>
void Heap<T,Comparator>::push(const T& item){
  items_.push_back(item);

  trickleup();
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return items_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
    items_[0] = items_.back();
    items_.pop_back();
    if(!empty()){
      trickledown();
    }
    
  
}


template<typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return (items_.empty());
}


template<typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return items_.size();
}



template <typename T, typename Comparator>
void Heap<T,Comparator>::trickleup(){
  int indx = items_.size()-1;
  while(indx>0){
    int parindx = (indx-1)/m_;
    if(c_(items_[indx],items_[parindx]) ){
      std::swap(items_[indx],items_[parindx]);
      indx = parindx;
    }
    else{
      break;
    }
  }
}



template <typename T, typename Comparator>
void Heap<T,Comparator>::trickledown(){
  int indx = 0;
  size_t child = indx*m_ + 1;
  size_t bestChild = child;

  
  while(child < items_.size()){
    child = indx*m_ + 1;
    bestChild = child;

    for(int i=0;i<m_;i++){
      if(child+i >= items_.size()){
        break;
      }
      if(c_(items_[child+i],items_[bestChild])){
        bestChild = child+i;
      }
    }

    if( c_(items_[bestChild],items_[indx]) ){
      std::swap(items_[bestChild],items_[indx]);
      indx = bestChild;
      child = m_*indx + 1;
    }
    else{
      break;
    }

  }
}


#endif

