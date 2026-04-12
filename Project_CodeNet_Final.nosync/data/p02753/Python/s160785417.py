#完全回答者のコピペです
d = list(input())
qa = 'Yes'
if d.count('A') == 3 or d.count('B') == 3:
    qa = 'No'
print(qa)