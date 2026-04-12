S = input()

is_bus_need = lambda S: (S != 'AAA') and (S != 'BBB')

answer = 'Yes' if is_bus_need(S) else 'No'

print(answer)
