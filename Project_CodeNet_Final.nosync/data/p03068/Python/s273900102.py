N = input()
strlist = list(input())
K = int(input())
target = strlist[K-1]
for i in range(int(N)):
    if strlist[i] != target:
        strlist[i] = '*'

print(''.join(strlist))