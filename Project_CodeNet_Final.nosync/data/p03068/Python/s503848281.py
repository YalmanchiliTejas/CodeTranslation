N = int(input())
S = input()
K = int(input())
fix = S[K-1]
message = "".join([character if character == fix else '*' for character in S])
print(message)