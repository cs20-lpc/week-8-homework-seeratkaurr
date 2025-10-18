template <typename T>
LinkedListStack<T>::LinkedListStack() {
    top = nullptr;
    this->length = 0;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    Node<T>* curr = top;
    while (curr != nullptr) {
        Node<T>* temp = curr;
        curr = curr->next;
        delete temp;
    }
    top = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    top = nullptr;
    this->length = 0;

    if (copyObj.top == nullptr)
        return;

  
    Node<T>* src = copyObj.top;
    Node<T>* prevNew = nullptr;
    Node<T>* newTop = nullptr;

    while (src != nullptr) {
        Node<T>* newNode = new Node<T>(src->data);
        if (newTop == nullptr)
            newTop = newNode;
        else
            prevNew->next = newNode;

        prevNew = newNode;
        src = src->next;
    }

    top = newTop;
    this->length = copyObj.length;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    if (isEmpty())
        throw string("peek: error, stack is empty, cannot access the top");
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    if (isEmpty())
        throw string("pop: error, stack is empty, avoiding underflow");

    Node<T>* temp = top;
    top = top->next;
    delete temp;
    this->length--;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    Node<T>* newNode = new Node<T>(elem);
    newNode->next = top;
    top = newNode;
    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    if (isEmpty())
        throw string("rotate: error
