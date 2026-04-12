N = int(input())
S = input()
K = int(input())

S_list = list(S)

moji = S_list[K-1]

for i in range(len(S_list)):
    if S_list[i]!=moji:
        S_list[i]="*"
print("".join(S_list))