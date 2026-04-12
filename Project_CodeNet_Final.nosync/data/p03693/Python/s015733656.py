#list(map(int, input().split()))
a,b,c=list(map(int, input().split()))
print('YES') if (b*10+c)%4==0 else print('NO')