
N=int(input())
S=input()
K=int(input())
letter=""

for i in S:
    if i is S[K-1]:
        letter +=i
    else:
        letter +="*"
print(letter)