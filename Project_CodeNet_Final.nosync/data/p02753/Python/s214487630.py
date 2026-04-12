input_lines=input()
word='No'
for i in range(2):
    if not input_lines[i]==input_lines[i+1]:
        word='Yes'
print(word)