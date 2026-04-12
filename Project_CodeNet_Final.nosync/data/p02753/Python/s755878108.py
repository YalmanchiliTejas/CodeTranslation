s = input()

company = s[0]
bus_needed = False
for i in range(1, len(s)):
    if company != s[i]:
        bus_needed = True
print("Yes" if bus_needed else "No")
