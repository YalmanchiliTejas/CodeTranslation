N = int(input())
S = input()
K = int(input())
print("".join([i if i==S[K-1] else "*" for i in S]))