N = int(input())
S = input()
K = int(input())

change_s = S[K-1]
change_after = ""
for n in range(N):
    if S[n] !=change_s:
        change_after += '*'
    else:
        change_after += S[n]
print(change_after)