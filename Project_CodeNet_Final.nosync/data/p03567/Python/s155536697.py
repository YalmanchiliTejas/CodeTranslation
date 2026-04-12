n = input()
ans = "No"
for i in range(len(n)-1):
    if n[i] == "A":
        if n[i+1] == "C":
            ans = "Yes"

print(ans)