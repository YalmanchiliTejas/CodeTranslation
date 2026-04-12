N = input()
A = list(map(int, input().split()));

max=0;
answer=0;

for i in A:
    if(max<=i):
        answer+=1;
        max=i;

print(answer);