N=int(input())
S=input()
K=int(input())

_char = S[K-1]
_char_indexes = [i for i in range(N) if S[i]==_char]
answer=list("*"*N)
for i in _char_indexes:
    answer[i]=_char
print("".join(answer))