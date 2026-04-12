from sys import stdin

N = stdin.readline().rstrip()
H_list = stdin.readline().rstrip().split()
H_list_int = list(map(lambda x: int(x), H_list))  # strリストをintリストへ

ables = 1
max = H_list_int.pop(0)

for i in H_list_int:
    if max <= i:
        ables += 1
        max = i

print(ables)