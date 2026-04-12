N = int(input())
S = input()
K = int(input())

change_word = S[K-1]
changed_S = ''

for w in S:
    if(w == change_word):
        changed_S += w
    else:
        changed_S += '*'

print(changed_S)