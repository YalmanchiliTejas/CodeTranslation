length=int(input())
string=list(input())
K=int(input())

key=string[K-1]

for i in range(length):
    if key != string[i]:
        string[i] = "*"
        
for j in range(length):
    print(string[j],end="")