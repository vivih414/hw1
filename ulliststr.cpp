#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
/**
* Adds a new value to the back of the list
*   - MUST RUN in O(1)
*/
void ULListStr::push_back(const std::string& val)
{
  //there is space at end
  if(tail_ != nullptr && tail_ -> last < ARRSIZE)
  {
    tail_ -> val[tail_ -> last] = val;
    tail_ -> last++;
  }
  else//no space at the end so create new node
  {
    Item* newItem = new Item();

    newItem -> val[0] = val;
    newItem -> first = 0;
    newItem -> last = 1;

    if(tail_ != nullptr)//if full adds to back
    {
      tail_ -> next = newItem;//connects tail to newItem
      newItem -> prev = tail_;
    }
    else
    {
      head_ = newItem;
    }

    tail_ = newItem;//tail now points to new node
  }
  size_++;
}

/**
* Removes a value from the back of the list
*   - MUST RUN in O(1)
*/
void ULListStr::pop_back()
{
  if(tail_ == nullptr)
  {
    return;
  }

   tail_ -> last = tail_ -> last - 1;

  if(tail_ -> first == tail_ -> last)//checks if tail node is empty
  {
    Item* temp = tail_;
    tail_ = tail_ -> prev;//moves pointer from tail to prev

    if(tail_ != nullptr)//disconnects from lists
    {
      tail_ -> next = nullptr;
    }
    else
    {
      head_ = nullptr;
    }
    delete temp;
  }
  size_--;//list decreases
}
  
/**
* Adds a new value to the front of the list.
* If there is room before the 'first' value in
* the head node add it there, otherwise, 
* allocate a new head node.
*   - MUST RUN in O(1)
*/
void ULListStr::push_front(const std::string& val)
{
  if(head_ != nullptr && head_ -> first > 0)
  {
    head_ -> first--;
    head_ -> val[head_ -> first] = val;
  }
  else//no space at the front so create new node
  {
    Item* newItem = new Item();

    newItem -> val[0] = val;
    newItem -> first = 0;
    newItem -> last = 1;

    if(head_ != nullptr)
    {
      newItem -> next = head_;
      head_ -> prev = newItem;
    }
    else
    {
      tail_ = newItem;
    }

    head_ = newItem;//head now points to new node
  }
  size_++;
}

/**
* Removes a value from the front of the list
*   - MUST RUN in O(1)
*/
void ULListStr::pop_front()
{
  if(head_ == nullptr)
  {
    return;
  }

  head_ -> first = head_ -> first + 1;

  if(head_ -> first == head_ -> last)//checks if head node is empty
  {
    Item* temp = head_;
    head_ = head_ -> next;//moves pointer from head to next

    if(head_ != nullptr)//disconnects from lists
    {
      head_ -> prev = nullptr;
    }
    else
    {
      tail_ = nullptr;
    }
    delete temp;
  }
  size_--;//list decreases
}
  
/**
* Returns a const reference to the back element
*   - MUST RUN in O(1)
*/
std::string const & ULListStr::back() const
{
  if(tail_ == nullptr)
  {
    throw std::runtime_error("List is empty");
  }
  return tail_ -> val[tail_ -> last - 1];
}

/**
* Returns a const reference to the front element
*   - MUST RUN in O(1)
*/
std::string const & ULListStr::front() const
{
  if(head_ == nullptr)
  {
    throw std::runtime_error("List is empty");
  }
  
  return head_ -> val[head_ -> first];
}

/** 
* Returns a pointer to the item at index, loc,
*  if loc is valid and NULL otherwise
*   - MUST RUN in O(n) 
*/
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc >= size_)
  {
    return nullptr;
  }

  Item* curr = head_;

  while(curr != nullptr)
  {
    size_t num = curr -> last - curr -> first;

    if(loc < num)
    {
      return &(curr -> val[curr -> first + loc]);
    }

    loc -= num;
    curr = curr -> next;
  }

  return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
