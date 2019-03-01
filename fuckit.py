import random
f = open("A/input.in", "r")
hor = []
vert = []
nr = -1
for line in f:
    if "H " in line:
        hor.append(nr)
    else:
        if "V " in line:
            vert.append(nr)
    nr = nr + 1

f = open("demofile.txt", "w+")
rez = []
print(int(len(vert)/2 + len(hor)))
while len(vert) != 0:
    string = ""
    nr = random.randint(0, len(vert)-1)
    string += str(vert[nr])
    vert.remove(vert[nr])
    string += " "
    nr = random.randint(0, len(vert)-1)
    string += str(vert[nr])
    vert.remove(vert[nr])
    rez.append(string)

while len(hor) != 0:
    string = ""
    nr = random.randint(0, len(hor)-1)
    rez.append(str(hor[nr]))
    hor.remove(hor[nr])

while len(rez) != 0:
    nr = random.randint(0, len(rez)-1)
    print(rez[nr])
    rez.remove(rez[nr])
