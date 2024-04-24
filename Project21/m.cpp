#include <iostream>
using namespace std;
typedef int KeyType;


//�����������Ľṹ�嶨��
typedef struct BSTNode {
	KeyType data; //������
	struct BSTNode* lchild;
	struct BSTNode* rchild; //�����������е���������������
}BSTNode, * BSTree;

//����
KeyType Delete(BSTree* p);
void Search();
void Insert();
void Del();


//��������������ڵ��㷨 ,�ݹ�ʵ��
void InsertBSTree(BSTree& T, KeyType k) {
	if (k < T->data) { //��������
		if (T->lchild == NULL) { //���������Ϊ�գ���ֱ�Ӹ�ֵ��������
			T->lchild = new BSTNode;
			T->lchild->data = k;
			T->lchild->lchild = NULL;
			T->lchild->rchild = NULL;
		}
		else { //�����������Ϊ�գ���ݹ������������
			InsertBSTree(T->lchild, k); 
		}
	}
	else { //��k�ȸ��ڵ��ֵ��ʱ����������
		if (T->rchild == NULL) { //���������Ϊ�գ�ֱ�Ӹ�ֵ
			T->rchild = new BSTNode;
			T->rchild->data = k;
			T->rchild->lchild = NULL;
			T->rchild->rchild = NULL;
		}
		else { //��������ݹ���������
			InsertBSTree(T->rchild, k);
		}
	}
}

//���������������㷨
void CreateBSTree(BSTree& T) {
	T = new BSTNode;
	T->lchild = NULL;
	T->rchild = NULL;
	int i;
	cin >> i; //��������ֵ
	if (i != -1) { //��ʼ�������������ڵ㸳��ֵ
		T->data = i;
	}
	while (i != -1) {
		cin >> i;
		if (i != -1) //����˫���жϣ���Ȼ-1��ӽ�����
			InsertBSTree(T, i);
	}

	cout << "�����ɹ���" << endl;
}

//�ݹ��ӡ�����õĶ���������
void PrintBSTree(BSTree T) { //����������������Եõ���С�������������
	if (T != NULL) {
		PrintBSTree(T->lchild);
		cout << T->data << " ";
		PrintBSTree(T->rchild);
	}
}

//�����������ĵݹ�����㷨
int SearchBSTree(BSTree T, int k) {
	if (T == NULL)
		return 0;
	if (T->data == k)
		return 1;
	if (k< T->data)
		SearchBSTree(T->lchild, k);
	else
		SearchBSTree(T->rchild, k);
}

//������������ɾ��������������
KeyType DeleteBST(BSTree* T, int k)
{
	if (!*T)
		return false;
	else
	{
		if (k == (*T)->data)
		{
			return Delete(T);
		}
		else if (k < (*T)->data)
		{
			return DeleteBST(&(*T)->lchild, k);
		}
		else
		{
			return DeleteBST(&(*T)->rchild, k);
		}
	}
}

//ɾ���ڵ�
KeyType Delete(BSTree* p)
{
	BSTree q, s;
	if ((*p)->rchild == NULL)
	{
		q = *p; *p = (*p)->lchild; free(q);
	}
	else if ((*p)->lchild == NULL)
	{
		q = *p; *p = (*p)->rchild; free(q);
	}
	else
	{
		q = *p; s = (*p)->lchild;
		while (s->rchild)
		{
			q = s; s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != *p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
	return true;
}



BSTree T;

int main() {

	cout << "���������У�(��-1Ϊ������)" << endl;
	CreateBSTree(T);
	cout << "�����õĶ�������������������Ϊ��" << endl;
	PrintBSTree(T);
	cout << endl;
	cout << "**************************************************************" << endl;
	cout << "ִ�в�����ţ�" << endl;
	cout << "1������		2������		3��ɾ��		4: ��������" << endl;
	cout << "**************************************************************" << endl;

	while (1)
	{
		int menu;
		cout << "������ִ�в�����ţ�";
		cin >> menu;
		switch (menu)
		{
		case 1:Search(); break;//����
		case 2:Insert(); break;//����
		case 3:Del();	 break;//ɾ��
		case 4:goto end; break;//��������
		default:cout << "������󣬱�Ų����ڡ�"; break;
		}
	}

end:
	return 0;
}

void Search()//���Ҳ���
{
	int i;
	cout << "������Ҫ���ҵ����֣�" << endl;
	cin >> i;
	if (SearchBSTree(T, i) == 0)
		cout << "����ʧ�ܣ���������û�д�����" << endl;
	if (SearchBSTree(T, i) == 1)
		cout << "���ҳɹ����������д��ڴ�����" << endl;
}

void Insert()//�������
{
	int i;
	cout << "��������Ҫ��������֣�";
	cin >> i;
	InsertBSTree(T, i);//���뺯��
	cout << "�����Ķ�������������������Ϊ��" << endl;
	PrintBSTree(T);
	cout << endl;
}

void Del()//ɾ������
{
	int i;
	cout << "��������Ҫɾ�������֣�";
	cin >> i;
	DeleteBST(&T, i);//ɾ������
	cout << "ɾ����Ķ�������������������Ϊ��" << endl;
	PrintBSTree(T);
	cout << endl;
}