l = input()
n = len(l)
stat = "No"
for i in range(n-1):
    if l[i] != l[i+1]:
        stat = "Yes"
        break

print(stat)