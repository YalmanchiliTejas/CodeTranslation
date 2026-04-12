a = int(input())
b = input()

c = b[int(input()) - 1]

s = [b[i] if b[i] == c else '*' for i in range(a)]

print(''.join(s))
