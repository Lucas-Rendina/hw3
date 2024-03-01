#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
private:
    std::vector<T> items;
};



template<typename T>
Stack<T>::Stack(){
    std::vector<T>();
}

template<typename T>
Stack<T>::~Stack(){
    while(!items.empty()){
        items.pop_back();
    }
}

template<typename T>
bool Stack<T>::empty() const{
    return items.empty();
}

template<typename T>
size_t Stack<T>::size() const{
    return items.size();
}

template<typename T>
void Stack<T>::push(const T& item){
    items.push_back(item);
}

template<typename T>
void Stack<T>::pop(){
    if(items.empty()){
        throw std::underflow_error("Shit's Empty(pop)");
    }
    else{
        items.pop_back();
    }
    
}

template<typename T>
const T& Stack<T>::top() const{
    if(items.empty()){
        throw std::underflow_error("Shit's Empty(top)");
    }
    else{
        return items.back();
    }
}





#endif