N=input()
s=input()
k=input()

N=int(N)
k=int(k)

ward=s[k-1]

for i in range(len(s)):
    if(s[i]==ward):
        print(ward ,end="")
    else:
        print("*" ,end="")
print("")
