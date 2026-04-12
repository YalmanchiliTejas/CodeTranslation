# 羊、狼をそれぞれ1,0と表記する
# 回答o,xをそれぞれ1,0と表記する

N = int(input())
s = list(input().replace("o", "1").replace("x", "0"))
s = list(map(int, s))

# 隣接する2匹の動物と右側の動物の回答を受けて、次の動物を返す
def next_animal(animal1, animal2, answer2):
    if (animal2 == 1 and answer2 == 1) or (animal2==0 and answer2==0):
        return animal1
    else:
        return 1^animal1

# 隣接する2匹の動物のパターン4通り×円順列に対するパターンN通りを試す
for first_two_animals in [[1,1],[1,0],[0,1],[0,0]]:
    animal_list = []
    animal_list.append(first_two_animals[0])
    animal_list.append(first_two_animals[1])

    for idx in range(2,N):
        animal_list.append(next_animal(animal_list[idx-2], animal_list[idx-1], s[idx-1]))

    # N番目の動物と回答が、状況と矛盾していないか確かめる
    if (s[0]==1 and animal_list[0]==1) or (s[0]==0 and animal_list[0]==0):
        last_animal = animal_list[1]
    else:
        last_animal = 1^animal_list[1]

    if (last_animal==1 and (animal_list[-2] == animal_list[0])) or (last_animal==0 and (animal_list[-2] != animal_list[0])):
        last_answer = 1
    else:
        last_answer = 0

    if last_animal == animal_list[-1] and last_answer == s[-1]:
        animal_list = list(map(str, animal_list))
        animal_list = [x.replace("1", "S").replace("0", "W") for x in animal_list]
        print("".join(animal_list))
        exit()

print(-1)