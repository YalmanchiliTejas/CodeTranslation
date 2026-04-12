#a,b=map(int,input().split())
a = int(input())
b=input()
b = b.split()
b = [int(i) for i in b]
kazu = 1
for i in range(0,a-1):
    c= [b[i] for i in range(0,i+1)]
    if b[i+1]>=max(c):
        kazu +=1
print(kazu)