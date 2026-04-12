a = int(input())
mozi = input()
b = int(input())

test = mozi[b-1]

ans = ""

for i in mozi:
    if i != test:
        ans+="*"
    else:
        ans+=i

print(ans)