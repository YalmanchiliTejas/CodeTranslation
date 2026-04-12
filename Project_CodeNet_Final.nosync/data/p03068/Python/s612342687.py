n = int(input())
s = input()
k = int(input())

c = s[k-1]

res = [ch if ch==c else '*' for ch in s]

print(''.join(res))
