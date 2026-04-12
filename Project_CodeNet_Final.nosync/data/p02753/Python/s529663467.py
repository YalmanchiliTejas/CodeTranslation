S=input()

pre=S[0]

ans='No'

for i in range(1,3):
    if S[i]!=pre:
        ans='Yes'
print(ans)