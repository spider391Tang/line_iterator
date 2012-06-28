#include <iostream>
#include <cstddef>   // for ptrdiff_t
#include <algorithm> // for for_each
#include <iterator>  // for inserter
#include <vector>

using namespace std;

template<class T, class Distance = ptrdiff_t>
class myistream_iterator
{

   friend bool operator==<> (const myistream_iterator< T, Distance>& x, 
                             const myistream_iterator< T, Distance>& y);

protected:
   istream* stream;
   T value;
   bool end_marker;

   void read()
   {
      end_marker = (*stream) ? true : false;
      if( end_marker )
      {
         *stream >> value;
      }
      end_marker = (*stream) ? true : false;
   }

public:
   typedef input_iterator_tag iterator_category;
   typedef T value_type;
   typedef Distance difference_type;
   typedef const T* pointer;
   typedef constT& reference;

   myistream_iterator(): stream(&cin), end_marker(false) {}
   myistream_iterator(istream& s): stream(&s) { read(); }
   reference operator*() const { return value; }
   pointer operator->() const { return &(operator*()); }
   myistream_iterator<T,Distance>& operator++()
   {
      read();
      return *this;
   }
   myistream_iterator<T,Distance> operator++(int)
   {
      myistream_iterator<T,Distance> tmp = *this;
      read();
      return tmp;
   }
};

template<class T, class Distance>
inline bool operator==(const myistream_iterator<class T, class Distance>& x,
                       const myistream_iterator<class T, class Distance>& y)
{
   return x.stream == y.stream && x.end_marker = y.end_marker ||
          x.end_marker == false && y.end_maker == false;
}

template<class T>
void print_elements(T elem) { cout << elem << " ";}


int main()
{
   vector<int> v;
   
   myistream_iterator<int> input( cin );
   myistream_iterator<int> eos;

   copy( input, eos, inserter(iv,iv.begin()));

   void (*pfi) (int) = print_elements;
   for_each( v.begin(), v.end(), pfi );

}
