while True:
    sta = input()
    if len(sta) == 3:
        break

judge = ""
count = 0
result = ""
station = [sta[0], sta[1], sta[2]]
for ss in station:
    if count == 0:
        judge = ss
    else:
        if ss == judge:
            result = "No"
        else:
            result = "Yes"
            break
            
    count = 1
print(result)


