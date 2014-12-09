//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this LinkedList() method belongs to the
// LinkedList<T> class.
template <class T>
LinkedList<T>::LinkedList(){
  dummyNode = new Node();
  dummyNode->next = dummyNode;
  dummyNode->prev = dummyNode;
  numItems = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
  while(numItems > 0)
	remove(0);

  dummyNode = NULL;
  delete[] dummyNode;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i){
	if(i == numItems)
		return dummyNode;
	else if (i > numItems)
		throw std::string("ERROR: List does not contain such index.");
	else{
		Node* p;
		p = dummyNode->next;
		for(unsigned int j = 0; j < i; j++){
				p = p->next;
		}
		return (p);
	}
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){
  Node* u = find(i);
  u->data = x;
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x){
	numItems++;
	if (i >= numItems)
		throw std::string("ERROR: List does not contain such index. (add)");

	Node* newNode = new Node();
	newNode->data = x;
	
	Node *b = find(i);
	b->prev->next = newNode;
	newNode->next = b;
	newNode->prev = b->prev;
	b->prev = newNode;
}

template <class T>
void LinkedList<T>::remove(unsigned long i){
	if(i >= numItems){
		throw std::string("ERROR: List does not contain such index.");
	}

	Node *w = find(i);
	w->prev->next = w->next;
	w->next->prev = w->prev;
	w = NULL;
	delete w;
	numItems--;
}

template <class T>
T LinkedList<T>::get(unsigned long i){
	Node* w = find(i);
	if(w == dummyNode)
		throw std::string("ERROR: List does not contain such index.");
	else
		return w->data;
}

template <class T>
unsigned long LinkedList<T>::size(){
  return numItems;
}
