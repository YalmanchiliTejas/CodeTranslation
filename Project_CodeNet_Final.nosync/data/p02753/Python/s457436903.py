data = input()

result = 'No'

if data.find('A') >= 0:
    if data.find('B') >= 0:
        result = 'Yes'

print(result)