#include <iostream>
using namespace std;

typedef struct{
	int data;
	int data2;
	int data3;
}data_type;

class Data
{
/* データ */
private:
	data_type data;

public:
	Data(data_type input);
	~Data();
	virtual void DataShow() {
		cout << "data:" << this->data.data << endl;
		cout << "data2:" << this->data.data2 << endl;
		cout << "data3:" << this->data.data3 << endl;
	}
};

Data::Data(data_type input)
{
	this->data.data = input.data;
	this->data.data2 = input.data2;
	this->data.data3 = input.data3;
}

Data::~Data()
{
	this->data.data = 0;
	this->data.data2 = 0;
	this->data.data3 = 0;
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

	/* 入力データ */
	data_type input = { 12,34,67 };

	/* データ格納 */
	test.addData(new Data(input));
	test.addData(new Data(input));
	test.addData(new Data(input));
	test.addData(new Data(input));

	/* データ表示 */
	test.show();
	return 0;
}