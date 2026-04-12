N = input()
S = input()
K = int(input())
 
char = S[K-1]
 
for s in S:
    print('*',end='') if s != char else print(s,end='')