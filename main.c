#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define true 1
#define false 0
#define MAX_ARRAY_LENGTH 10

struct Shape_Mother;

typedef void (*F_Ptr)(struct Shape_Mother*);

struct Shape_Mother
{
	int m;
	F_Ptr* func_array;
};

void draw(struct Shape_Mother* mom)
{
	printf("Hello, guys !\n");
	
}

void draw1(struct Shape_Mother* mom)
{
	printf("Hello, suckers !\n");
}

typedef struct Shape_Child
{
	struct Shape_Mother* mother;
	int c;
	F_Ptr draw;
} Shape_Child;


void initShape(struct Shape_Mother* Mom)
{
	Mom->m = 1;
	Mom->func_array = (F_Ptr*)calloc(MAX_ARRAY_LENGTH, sizeof(F_Ptr));
	for (int i = 0; i < MAX_ARRAY_LENGTH; ++i)
	{
		Mom->func_array[i] = NULL;
	}
}

struct Shape_Child* make_shape(struct Shape_Mother* mom, int i)
{
	struct Shape_Child* child = (struct Shape_Child*)malloc(sizeof(struct Shape_Child));
	child->mother = mom;
	child->c = 2;
	if (i != 1) {
		child->draw = draw1;
	}
	else
	{
		child->draw = draw;
	}
	for (int i = 0; i < MAX_ARRAY_LENGTH; ++i)
	{
		if (child->mother->func_array[i] == NULL)
		{
			int var = 0;
			child->mother->func_array[i] = child->draw;
			break;
		}
	}

}

void general_draw(struct Shape_Mother* mother)
{
	for (int i = 0; i < MAX_ARRAY_LENGTH && mother->func_array[i] != NULL; ++i)
	{
		mother->func_array[i](mother);
	}

}

int main()
{
	struct Shape_Mother base;
	initShape(&base);
	struct Shape_Child* shape = make_shape(&base, 1);
	struct Shape_Child* shape_1 = make_shape(&base, 2);

	general_draw(&base);

	system("pause");
	return 0;
}