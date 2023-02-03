//32 i poxaren sizeof(int) em grum sxal e tpum

#include <iostream>

class Bitset
{
	private:
		int m_size;
		unsigned int* m_arr;
	public:
		Bitset(int x);
	public: 
		void set(int);
		void reset(int); 
};

Bitset::Bitset(int x): m_size{x} 
{
	m_size = x; 
	m_arr = new unsigned int[m_size];
} 

void Bitset::set(int x)
{
	int index = x/32;
	x = x % 32;
	int tmp = m_arr[index];
	m_arr[index] = m_arr[index] >> x;
	m_arr[index] = m_arr[index] | 1;
	m_arr[index] = m_arr[index] << x;
	m_arr[index] = m_arr[index] | tmp; 
	std::cout << m_arr[index] << "  set:" << x << std::endl;
}

void Bitset::reset(int x)
{
	int index = x/32;
	x = x % 32;
	unsigned int tmp = m_arr[index];
	tmp = tmp >> (x + 1);
	tmp = tmp << (x + 1);
	unsigned int chlp = m_arr[index];
	chlp = chlp << (32 - x);
	chlp = chlp >> (32 - x);
	m_arr[index] = chlp | tmp;
	std::cout << m_arr[index] << "  reset:" << x <<std::endl;
	
}

Bitset creation()
{
	std::cout << "insert amount of bits\n";
	int num;
	std::cin >> num;
	int index;
	index = num/32 + 1;
	Bitset bitset(index);
	return bitset;
}


int main()
{
	Bitset bitset = creation();
	bitset.set(0);
	bitset.set(1);
	bitset.set(2);
	bitset.set(3);
	bitset.set(4);
	
	bitset.set(4);
	bitset.set(3);
	bitset.set(2);
	bitset.reset(4);
}

