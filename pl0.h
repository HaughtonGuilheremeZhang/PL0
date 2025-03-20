                         /*PL/0 编译系统C版本头文件 pl0.h*/
//*******************
//此范围为修改的地方
//*******************

//*************************************
# define norw 26		//关键字增加
//*************************************

# define txmax 100               /*名字表容量*/
# define nmax  14                /*number的最大位数*/
# define al 10                   /*符号的最大长度*/
# define amax 2047               /*地址上界*/
# define levmax 3                /*最大允许过程嵌套声明层数[0，lexmax]*/
# define cxmax 500               /*最多的虚拟机代码数*/
/*符号*/
enum symbol{
nul,    ident,     number,     plus,     minus,
times,   slash,   oddsym,   eql,     neq,
lss,     leq,      gtr,     geq,     lparen,
rparen,  comma,   semicolon,period,  becomes,
beginsym, endsym, ifsym,    thensym,  whilesym,
writesym, readsym,  dosym,  callsym,  constsym,
varsym,  procsym,
elsesym, repeatsym, untilsym, returnsym, 
forsym,tosym,downtosym,//增加for语句关键字
addbecomes,//运算符+=
minusbecomes,//运算符-=
timesbecomes,//运算符*=
slashbecomes,//运算符/=
incsym,//运算符++
decsym,//运算符--
lepa,//数组的左括号[
ripa,//数组的右括号]
mod,//取余
};

//****************************************************************
//此数组是为了词法分析输出保留字而建立的
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
//错误原因说明字符数组
char *errortxt[]=
{
	//错误原因																	出错编号
	const_cast<char*>("0"),																			//0没有使用
	const_cast<char*>("常数说明中的\"=\"写成\":=\""),												//1
	const_cast<char*>("常数说明中的\"=\"后应是数字"),												//2
	const_cast<char*>("常数说明中的标识符后应是\"=\""),											//3
	const_cast<char*>("const,var,procedure后应为标识符"),											//4
	const_cast<char*>("漏掉了\",\"或者\";\""),														//5
	const_cast<char*>("过程说明后的符号不正确（应是语句开始符，或过程定义符）"),					//6
	const_cast<char*>("应是语句开始符"),															//7
	const_cast<char*>("repeat语句缺少\"until\""),											    	//8
	const_cast<char*>("程序结尾丢了句号\".\""),													//9
	const_cast<char*>("语句之间漏了\";\""),														//10
	const_cast<char*>("标识符未说明"),																//11
	const_cast<char*>("赋值语句中，赋值号左部标识符属性应是变量"),									//12
	const_cast<char*>("赋值语句左部标识符后应是赋值号\":=\"、\"+=\"、\"-=\"、\"*=\"、\"/=\""),		//13
	const_cast<char*>("call后应为标识符"),															//14
	const_cast<char*>("call后标识符属性应为过程"),													//15
	const_cast<char*>("条件语句中丢了\"then\""),													//16
	const_cast<char*>("丢了\"end\"或者\";\""),														//17
	const_cast<char*>("while型循环语句中丢了\"do\""),												//18
	const_cast<char*>("for语句后跟赋值语句，赋值语句左部是变量，缺少变量"),						//19
	const_cast<char*>("运算符不是关系运算符"),														//20
	const_cast<char*>("表达式内标识符属性不能是过程"),												//21
	const_cast<char*>("表达式中漏掉右括号"),														//22
	const_cast<char*>("因子后的非法符号"),															//23
	const_cast<char*>("表达式的开始符不正确"),														//24
	const_cast<char*>("数组下标定义不符合规定，应为常量"),											//25
	const_cast<char*>("数组缺少右中括号\"]\""),													//26
	const_cast<char*>("数组变量后跟着\"[\""),														//27
	const_cast<char*>("数组下标越界"),																//28
	const_cast<char*>("for语句中缺少了\"do\""),													//29
	const_cast<char*>("数字的长度太长"),															//30
	const_cast<char*>("数超出规定的界限"),															//31
	const_cast<char*>("当前分程序所在层层次超过规定的最大层次"),									//32
	const_cast<char*>("read和write语句中，缺少右括号\")\""),										//33
	const_cast<char*>("read和write语句中，缺少左括号"),											//34
	const_cast<char*>("read语句中，()里必须是标识符")												//35
};

/*--标识符的类型属性--*/
enum object{
   constant,
   variable,
   procedur,
   array,
};
/*---虚拟机代码指令操作码---*/
enum fct{
lit, opr,  lod,  sto,  cal,  inte,  jmp,  jpc, 
gar,//根据栈顶的偏移地址从数组中取值到新的栈顶
sar,//根据次栈顶的偏移地址把栈顶的值存入数组
shd,//将栈顶的值下移到次栈顶，栈顶出栈，即次栈顶成为栈顶
del,//出栈顶
jud,//判断数组下标合法性
tra,//将数组的下标范围入栈，gendo(tra,0,数组下标最大值);
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
   char name[al];                            /*名字*/
   enum object kind;                         /*类型：const，var，array or procedure*/
   int val;                                  /*数值，仅const使用*/
   int level;                                /*所处层，仅const不使用*/
   int adr;                                  /*地址，仅const不使用*/
   int size;                                 /*需要分配的数据区空间，仅procedure使用*/
};
struct tablestruct table[txmax];             /*名字表*/
FILE * fin;
FILE* fout;
char fname[al];
int err;                                       /*错误计数器*/
/*当函数中会发生fatal error时，返回－1告知调用它的函数，最终退出程序*/
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

        








