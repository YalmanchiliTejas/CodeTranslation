args = input().split(' ')

N = int(args[0])
M = int(args[1])

isAccepted = (N == M)

print("Yes" if isAccepted else "No")