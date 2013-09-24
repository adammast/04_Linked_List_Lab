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
  
   numItems = 0;
  
}

template <class T>
LinkedList<T>::~LinkedList()
{
      
    delete dummyNode;
    
    for(int i = 0;i < numItems;i++)
    {
             remove(0);
    }
    
       
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(unsigned long i)
{
  if(i == (unsigned long)-1)
  
  {

	  return dummyNode;
	  
  }
   
  if(i<0 || i>=numItems)
  {
  
	  throw std::string("Invalid index.");

  }
  
  //Crate a head node points to the head of the list.
  Node * head = new Node();
  head = dummyNode ->next;
  
  for(int j=0; j<numItems; j++)
  {
	  if(j == i)
	  {	
		  return head;
	  }

	  head = head -> next;
  }
  
  return NULL;
}

template <class T>
void LinkedList<T>::set(unsigned long i, T x){

     if( i < 0 || i >= numItems)
	  {

	  throw std :: string("Error! Invalid index!");

	  }

    //Creat a pointer points to the index i.
    Node * PointTo = find(i);
    
    //Set the value of index i to x.
    PointTo ->data = x;
   
    
}

template <class T>
void LinkedList<T>::add(unsigned long i, T x)
{

  //Create a pointer points to the previous index of the index you want to return.
  Node * n = new Node();
  n -> prev = find(i-1);
  
  //Create a memory block in the heap.
  Node * newNode = new Node();
  
  //Store the data in this memory block.
  newNode -> data = x;
  
  //Be very careful the order of setting the pointer here.
  //You must let the (newNode->next) points to (prevIndex -> next) before 
  //you let the (prevIndex -> next) points to newNode .
  //If you let the (prevIndex -> next) points to newNode first,
  //and then you will completely lose the reference after prevIndex,
  //and there is no way to access it again.
  
  newNode -> next = (n -> prev) ->next;
  
  (n -> prev) -> next = newNode;
  
  numItems++;

}

template <class T>
void LinkedList<T>::remove(unsigned long i)
{
    if( i < 0 || i >= numItems)
     {
         throw std :: string("Error! Invalid index!");     
     }
    
    if( numItems == 0)
     {
       throw std :: string("There is no item to delete.");         
     }
    
     Node * tmp = find(i-1);
     Node * toRemove = tmp->next;
     if(toRemove == NULL)
     {
     throw std :: string("Error! Invalid index!");     
     }
     tmp->next = toRemove->next;
     delete toRemove;
     numItems--;
     
    
}

template <class T>
T LinkedList<T>::get(unsigned long i){
  
    if( i < 0 || i >= numItems)
	   {

	  throw std :: string("Error! Invalid index!");

	 }

     Node * ret = find(i);
     
     
     return (ret ->data);
  

}

template <class T>
void LinkedList<T>::splice(unsigned long i, unsigned long len, List<T>& target, unsigned long t){
  //TODO
}

template <class T>
unsigned long LinkedList<T>::size(){
  
  return numItems;
  
}
