                         /*PL/0 ����ϵͳC�汾ͷ�ļ� pl0.h*/
//*******************
//�˷�ΧΪ�޸ĵĵط�
//*******************

//*************************************
# define norw 26		//�ؼ�������
//*************************************

# define txmax 100               /*���ֱ�����*/
# define nmax  14                /*number�����λ��*/
# define al 10                   /*���ŵ���󳤶�*/
# define amax 2047               /*��ַ�Ͻ�*/
# define levmax 3                /*����������Ƕ����������[0��lexmax]*/
# define cxmax 500               /*���������������*/
/*����*/
enum symbol{
nul,    ident,     number,     plus,     minus,
times,   slash,   oddsym,   eql,     neq,
lss,     leq,      gtr,     geq,     lparen,
rparen,  comma,   semicolon,period,  becomes,
beginsym, endsym, ifsym,    thensym,  whilesym,
writesym, readsym,  dosym,  callsym,  constsym,
varsym,  procsym,
elsesym, repeatsym, untilsym, returnsym, 
forsym,tosym,downtosym,//����for���ؼ���
addbecomes,//�����+=
minusbecomes,//�����-=
timesbecomes,//�����*=
slashbecomes,//�����/=
incsym,//�����++
decsym,//�����--
lepa,//�����������[
ripa,//�����������]
mod,//ȡ��
};

//****************************************************************
//��������Ϊ�˴ʷ�������������ֶ�������
char ch1[] = "nul";
char ch2[] = "ident";
char ch3[] = "number";
char ch4[] = "plus";
char ch5[] = "minus";
char ch6[] = "times";
char ch7[] = "slash";
char ch8[] = "oddsym";
char ch9[] = "eql";
char ch10[] = "neq";
char ch11[] = "lss";
char ch12[] = "leq";
char ch13[] = "gtr";
char ch14[] = "geq";
char ch15[] = "lparen";
char ch16[] = "rparen";
char ch17[] = "comma";
char ch18[] = "semicolon";
char ch19[] = "period";
char ch20[] = "becomes";
char ch21[] = "beginsym";
char ch22[] = "endsym";
char ch23[] = "ifsym";
char ch24[] = "whilesym";
char ch25[] = "writesym";
char ch26[] = "readsym";
char ch27[] = "dosym";
char ch28[] = "callsym";
char ch29[] = "constsym";
char ch30[] = "varsym";
char ch31[] = "procsym";
char ch32[] = "elsesym";
char ch33[] = "repeatsym";
char ch34[] = "untilsym";
char ch35[] = "returnsym";
char ch36[] = "forsym";
char ch37[] = "stepsym";
char ch38[] = "tosym";
char ch39[] = "downtosym";
char ch40[] = "addbecomes";
char ch41[] = "minusbecomes";
char ch42[] = "timesbecomes";
char ch43[] = "slashbecomes";
char ch44[] = "inc";
char ch45[] = "dec";
char ch46[] = "lepa";
char ch47[] = "ripa";
char ch48[] = "mod";
char *symout[] = {
	ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,ch10,ch11,ch12,ch13,ch14,ch15,ch16,ch17,ch18,ch19,ch20,
	ch21,ch22,ch23,ch24,ch25,ch26,ch27,ch28,ch29,ch30,ch31,ch32,ch33,ch34,ch35,ch36,ch37, ch38,
	ch39,ch40,ch41,ch42,ch43,ch44,ch45,ch46,ch47,ch48,
};
//****************************************************************
#define symnum 48		
//****************************************************************
//����ԭ��˵���ַ�����
char *errortxt[]=
{
	//����ԭ��																	������
	const_cast<char*>("0"),																			//0û��ʹ��
	const_cast<char*>("����˵���е�\"=\"д��\":=\""),												//1
	const_cast<char*>("����˵���е�\"=\"��Ӧ������"),												//2
	const_cast<char*>("����˵���еı�ʶ����Ӧ��\"=\""),											//3
	const_cast<char*>("const,var,procedure��ӦΪ��ʶ��"),											//4
	const_cast<char*>("©����\",\"����\";\""),														//5
	const_cast<char*>("����˵����ķ��Ų���ȷ��Ӧ����俪ʼ��������̶������"),					//6
	const_cast<char*>("Ӧ����俪ʼ��"),															//7
	const_cast<char*>("repeat���ȱ��\"until\""),											    	//8
	const_cast<char*>("�����β���˾��\".\""),													//9
	const_cast<char*>("���֮��©��\";\""),														//10
	const_cast<char*>("��ʶ��δ˵��"),																//11
	const_cast<char*>("��ֵ����У���ֵ���󲿱�ʶ������Ӧ�Ǳ���"),									//12
	const_cast<char*>("��ֵ����󲿱�ʶ����Ӧ�Ǹ�ֵ��\":=\"��\"+=\"��\"-=\"��\"*=\"��\"/=\""),		//13
	const_cast<char*>("call��ӦΪ��ʶ��"),															//14
	const_cast<char*>("call���ʶ������ӦΪ����"),													//15
	const_cast<char*>("��������ж���\"then\""),													//16
	const_cast<char*>("����\"end\"����\";\""),														//17
	const_cast<char*>("while��ѭ������ж���\"do\""),												//18
	const_cast<char*>("for�������ֵ��䣬��ֵ������Ǳ�����ȱ�ٱ���"),						//19
	const_cast<char*>("��������ǹ�ϵ�����"),														//20
	const_cast<char*>("���ʽ�ڱ�ʶ�����Բ����ǹ���"),												//21
	const_cast<char*>("���ʽ��©��������"),														//22
	const_cast<char*>("���Ӻ�ķǷ�����"),															//23
	const_cast<char*>("���ʽ�Ŀ�ʼ������ȷ"),														//24
	const_cast<char*>("�����±궨�岻���Ϲ涨��ӦΪ����"),											//25
	const_cast<char*>("����ȱ����������\"]\""),													//26
	const_cast<char*>("������������\"[\""),														//27
	const_cast<char*>("�����±�Խ��"),																//28
	const_cast<char*>("for�����ȱ����\"do\""),													//29
	const_cast<char*>("���ֵĳ���̫��"),															//30
	const_cast<char*>("�������涨�Ľ���"),															//31
	const_cast<char*>("��ǰ�ֳ������ڲ��γ����涨�������"),									//32
	const_cast<char*>("read��write����У�ȱ��������\")\""),										//33
	const_cast<char*>("read��write����У�ȱ��������"),											//34
	const_cast<char*>("read����У�()������Ǳ�ʶ��")												//35
};

/*--��ʶ������������--*/
enum object{
   constant,
   variable,
   procedur,
   array,
};
/*---���������ָ�������---*/
enum fct{
lit, opr,  lod,  sto,  cal,  inte,  jmp,  jpc, 
gar,//����ջ����ƫ�Ƶ�ַ��������ȡֵ���µ�ջ��
sar,//���ݴ�ջ����ƫ�Ƶ�ַ��ջ����ֵ��������
shd,//��ջ����ֵ���Ƶ���ջ����ջ����ջ������ջ����Ϊջ��
del,//��ջ��
jud,//�ж������±�Ϸ���
tra,//��������±귶Χ��ջ��gendo(tra,0,�����±����ֵ);
};
#define fctnum 14
/*--------------*/
struct instruction
{
  enum fct f;
  int l;
  int a;
};

FILE * fas;
FILE * fa;
FILE * fa1;
FILE * fa2;

bool tableswitch;
bool listswitch;
char ch;
enum symbol sym;
char id[al+1];
int  num;
int  arraysize;
int cc,ll;
int cx;
char line[81];
char a[al+1];
struct instruction code[cxmax];
char word[norw][al];
enum symbol wsym[norw];
enum symbol ssym[256];
char mnemonic[fctnum][5];
bool declbegsys[symnum];
bool statbegsys[symnum];
bool facbegsys[symnum];
/*------------------------------*/

struct tablestruct
{
   char name[al];                            /*����*/
   enum object kind;                         /*���ͣ�const��var��array or procedure*/
   int val;                                  /*��ֵ����constʹ��*/
   int level;                                /*�����㣬��const��ʹ��*/
   int adr;                                  /*��ַ����const��ʹ��*/
   int size;                                 /*��Ҫ������������ռ䣬��procedureʹ��*/
};
struct tablestruct table[txmax];             /*���ֱ�*/
FILE * fin;
FILE* fout;
char fname[al];
int err;                                       /*���������*/
/*�������лᷢ��fatal errorʱ�����أ�1��֪�������ĺ����������˳�����*/
#define getsymdo                              if(-1==getsym())return -1
#define getchdo                               if(-1==getch())return -1
#define testdo(a,b,c)                         if(-1==test(a,b,c))return -1
#define gendo(a,b,c)                          if(-1==gen(a,b,c))return -1
#define expressiondo(a,b,c)                   if(-1==expression(a,b,c))return -1
#define factordo(a,b,c)                       if(-1==factor(a,b,c))return -1
#define termdo(a,b,c)                         if(-1==term(a,b,c))return -1
#define conditiondo(a,b,c)                    if(-1==condition(a,b,c))return -1
#define statementdo(a,b,c)                    if(-1==statement(a,b,c))return -1
#define constdeclarationdo(a,b,c)             if(-1==constdeclaration(a,b,c))return -1
#define vardeclarationdo(a,b,c)               if(-1==vardeclaration(a,b,c))return -1
void error(int n);
int getsym();
int getch();
void init();
int gen(enum fct x,int y,int z);
int test(bool*s1,bool*s2,int n);
int inset(int e,bool*s);
int addset(bool*sr,bool*s1,bool*s2,int n);
int subset(bool*sr,bool*s1,bool*s2,int n);
int mulset(bool*sr,bool*s1,bool*s2,int n);
int block(int lev,int tx,bool* fsys);
void interpret();
int factor(bool* fsys,int* ptx,int lev);
int term(bool*fsys,int*ptx,int lev);
int condition(bool*fsys,int*ptx,int lev);
int expression(bool*fsys,int*ptx,int lev);
int statement(bool*fsys,int*ptx,int lev);
void listcode(int cx0);
int vardeclaration(int* ptx,int lev, int* pdx);
int constdeclaration(int* ptx,int lev, int* pdx);
int position(char* idt,int tx);
void enter(enum object k,int* ptx,int lev,int* pdx);
int base(int l,int* s,int b);

        








