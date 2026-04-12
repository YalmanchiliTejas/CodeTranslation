list_n = input()
list_n = list(list_n)
ans = "No"
for i in range(2):
    if list_n[i] != list_n[i+1]:
        ans = "Yes"

print(ans)