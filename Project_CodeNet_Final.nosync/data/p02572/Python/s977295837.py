n = int(input())
l = input()
a = l.split(' ')

tmp = 0
tmp2 = 0

for i in range(n):
    tmp += int(a[i])

for i in range(n):
    tmp2 += int(a[i])*int(a[i])

print(int((tmp*tmp-tmp2)//2)%1000000007)