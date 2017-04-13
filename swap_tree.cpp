#include < iostream > 
#include < stdlib.h >

  using namespace std;
struct node {
  int info;
  struct node * l, * r;
};

typedef struct node * nodeptr;

void create(nodeptr & t) {
  char x;
  if (t == 0) {
    t = new node();
    t-> l = 0;
    t-> r = 0;
    cout << "enter the info";
    cin >> t-> info;
    cout << "insert from the left y/n " << t-> info;
    cin >> x;
    if (x == 'y')
      create(t-> l);
    cout << "insert from the right y/n " << t-> info;
    cin >> x;
    if (x == 'y')
      create(t-> r);
  }
}

void print(nodeptr t) {
  if (t != 0) {
    cout << t-> info;
    print(t-> l);
    print(t-> r);
  }
}

int main() {
  nodeptr h, p, t;
  t = 0;
  create(t);
  print(t);    // 100 30 70 80 50 12
  cout << endl;
  p = t-> l;
  h = t-> r;
  t-> r = p;
  t-> l = h;
  print(t);  // 100 80 50 12 30 70

  return 0;
}
