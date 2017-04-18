#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main()
{
	char buf[1000];
	while(cin.getline(buf,1000))
	{
		if(buf[0]=='*')
			break;
		int move=0,over=strlen(buf)-1,flag=1;
		while(buf[move]==' ')
			move++;//不读空格
		int p_count=0,e_count=0;
		for(int i=move;i<=over;++i)
		{
			if(buf[i]=='.')
				p_count++;
			if(buf[i]=='e'||buf[i]=='E')
				e_count++;
		}
		if(e_count>1||p_count>1||e_count+p_count==0)
			flag=0;
		int last=over,start=move;
		if(flag&&e_count==1)
		{
			for(int i=move;i<=over;++i)
				if(buf[i]=='e'||buf[i]=='E')
				{
					if(i==move||i==over)
						flag=0;
					over=i-1;
					start=i+1;
					break;
				}
			if(buf[start]=='+'||buf[start]=='-')
				start++;
			for (int i=start;i<=last;++i)
				if (buf[i]<'0'||buf[i]>'9')
				{
					flag=0;
					break;
				}
		}

		if(flag)
		{
			int from=0;
			if(buf[move]=='+'||buf[move]=='-')
				from=1;
			for(int i=move+from;i<=over;++i)
				if (p_count==1&&buf[i]=='.'&&i<over&&i>move+from)
					continue;
				else if(buf[i]<'0'||buf[i]>'9')
				{
					flag=0;
					break;
				}
		}
		for(int i=move;i<=last;++i)
			printf("%c",buf[i]);
		if(flag)
			printf(" is legal.\n");
		else printf(" is illegal.\n");
	}
	return 0;
}
