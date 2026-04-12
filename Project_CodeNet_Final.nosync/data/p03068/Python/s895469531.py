N = int(input())
S = input()
K = int(input())

target = S[K - 1]
print(''.join([c if c == target else '*' for c in S]))