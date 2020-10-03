#include <iostream>
using namespace std;


class Data
{
private:
	int data;
	int data2;
	int data3;

public:
	Data(int data, int data2, int data3);
	~Data();
	virtual void DataShow() {
		cout << "data:" << this->data << endl;
		cout << "data2:" << this->data2 << endl;
		cout << "data3:" << this->data3 << endl;
	}
};

Data::Data(int data, int data2, int data3)
{
	this->data = data;
	this->data2 = data2;
	this->data3 = data3;
}

Data::~Data()
{
	this->data = 0;
	this->data2 = 0;
	this->data3 = 0;
}

class DataCollect {
private:
	Data** li;
	int p;
	int limit;
public:
	DataCollect(int num) {
		li = new Data * [num];
		p = 0;
		limit = num;
	}

	void addData(Data *data) {
		if (this->p >= this->limit) {
			cout << "Data Full" << endl;
			return;
		}
		this->li[p++] = data;
	}

	void show(){
		for (int loop = 0; loop < p; loop++) {
			li[loop]->DataShow();
		}
	}
};


int main() {

	/* データ格納変数 */
	DataCollect test(3);

	/* データ格納 */
	test.addData(new Data(12, 34, 56));
	test.addData(new Data(12, 34, 56));
	test.addData(new Data(12, 34, 56));
	test.addData(new Data(12, 34, 56));
	/* データ表示 */
	test.show();





	return 0;

}