n = int(input())
s = list(input())
k = int(input())
nm = s[k-1]
for i in s:
    if i != nm:
        print('*',end='')
    else:
        print(i,end='')
print()