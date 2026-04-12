station=input()

flg="No"
for i in range(2):
    if station[i]!=station[i+1]:
        flg="Yes"

print(flg)