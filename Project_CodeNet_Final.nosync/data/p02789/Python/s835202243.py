input_line = input()

qwestion,answer = input_line.split()

judge = 'Yes'

if qwestion != answer:
    judge = 'No'
    
print(judge) 