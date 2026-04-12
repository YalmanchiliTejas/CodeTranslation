import sys
input = sys.stdin.readline

n = int(input())
s = input()
s = list(s)

k = int(input())

temp = s[k-1]

# print(temp)

for i in range(n):
    if s[i] != temp:
        s[i] = '*'

# print(s)
s = ''.join(s)
print(s)