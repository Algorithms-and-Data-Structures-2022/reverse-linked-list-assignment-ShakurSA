#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    // Напишите здесь свой код ...
    Node* current = front_;
    back_ = current;
    Node* prev = nullptr;
    Node* next;
    while (current != nullptr) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    front_ = prev;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (0 < size_){
      reverse_recursive_helper(front_->next, front_);
      Node* start = front_;
      front_->next = nullptr;
      front_ = back_;
      back_ = start;
    }
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (nullptr == curr){
      return;
    }
    reverse_recursive_helper(curr->next, curr);
    curr->next = prev;
  }

}  // namespace assignment
