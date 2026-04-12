n=int(input())
s=input()
k=int(input())

token=s[k-1]

print("".join(["*" if w!=token else w for w in s]))