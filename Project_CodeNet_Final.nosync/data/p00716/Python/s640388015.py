trial = int(input())
for t in range(trial):
    money = int(input())
    year = int(input())
    cond = int(input())
    answer = 0
    
    for c in range(cond):
        initial = money
        bank = [float(n) for n in input().split(" ")]
        if bank[0] == 0:
            interest = 0
            for y in range(year):
                interest += int(initial * bank[1])
                initial -= bank[2]
            else:
                #print(interest + initial)
                if answer < interest + initial:
                    answer = int(interest + initial)
        else:
            for y in range(year):
                initial = initial + int(initial * bank[1] )
                initial -= bank[2]
            else:
                #print(initial)
                if answer < initial:
                    answer = int(initial)
    else:
        print(answer)