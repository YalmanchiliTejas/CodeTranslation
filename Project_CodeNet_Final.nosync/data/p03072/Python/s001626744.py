n = input()
input_char = input()
input_char = input_char.split(" ")

mountains_heigh = [int(h) for h in input_char]

viewable_count = 1
for idx,h in enumerate(mountains_heigh):
    if idx >0 :
        max_h_behind = max(mountains_heigh[:idx])
        if max_h_behind <= h :
            viewable_count+= 1

print(viewable_count)