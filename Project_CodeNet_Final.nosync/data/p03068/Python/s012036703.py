n, s, k = [input() for _ in range(3)]
n, k = int(n), int(k) - 1
t = s[k]
print(''.join([c if c == t else '*' for c in s]))
