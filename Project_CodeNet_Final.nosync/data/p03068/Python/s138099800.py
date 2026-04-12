n = int(input())
s = input()
k = int(input())

o = s[k-1]
ans = [i if i == o else '*' for i in s]
print(''.join(ans))
