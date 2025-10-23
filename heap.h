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
// helper functions
void heapify(int ind);
void swap(int a, int b);
// data members
std::vector<T> data;
int m_ary;
PComparator compare;


};


// Add implementation of member functions here

// helper functions

template <typename T, typename PComparator>
void Heap<T,PComparator>::swap(int a, int b)
{
  T temp = data[a];
  data[a] = data[b];
  data[b] = temp;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int ind)
{

  int best = ind;
  int firstChild = m_ary * ind + 1;
  for(int i = 0; i < m_ary; i++){
    int childIndex = firstChild + i;
    if(childIndex < (int)size() && compare(data[childIndex], data[best])){
      best = childIndex;
    }
  }
  if(best != ind){
    swap(ind, best);
    heapify(best);
  }
}

// main functions


template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c): m_ary(m)
{
  compare = c;
}
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{}


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  // push to the last position
  data.push_back(item);

  // trickle up
  int index = size() - 1;
  int parent = (index - 1) / m_ary;
  while(index > 0 && compare(data[index], data[parent])){
    swap(index, parent);
    index = parent;
    parent = (index - 1) / m_ary;
  }
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
    throw std::underflow_error("Empty Heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];
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
    throw std::underflow_error("Empty Heap");
  }
  swap(0, size() - 1);
  data.pop_back();
  if(!empty()){
    heapify(0); // trickle down
  }
}

// Empty()
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  if(size() == 0){
    return true;
  }
  return false;
}

// Size()
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return data.size();
}




#endif

