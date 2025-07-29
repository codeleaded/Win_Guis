//#include "C:/Wichtig/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Random.h"
#include "/home/codeleaded/System/Static/Library/Scene.h"


Scene scene;

void Button1_React(Button* b,ButtonEvent* be){

}
void Button2_React(Button* b,ButtonEvent* be){

}
void Button3_React(Button* b,ButtonEvent* be){

}

void Setup(AlxWindow* w){
	scene = Scene_New();

	Scene_Add(&scene,(Button[]){
		Button_NewStd(
			(void*)&scene,
			"Hello World",
			Button1_React,
			(Vec2){ 32.0f,32.0f },
			Rect_New((Vec2){ 0.0f,0.0f },(Vec2){ 400.0f,100.0f }),
			RED,
			GREEN
		) 
	},sizeof(Button));
	Scene_Add(&scene,(Button[]){
		Button_NewStd(
			(void*)&scene,
			"Hello World",
			Button2_React,
			(Vec2){ 32.0f,32.0f },
			Rect_New((Vec2){ 400.0f,0.0f },(Vec2){ 400.0f,100.0f }),
			RED,
			GREEN
		) 
	},sizeof(Button));
	Scene_Add(&scene,(Button[]){
		Button_NewStd(
			(void*)&scene,
			"Hello World",
			Button3_React,
			(Vec2){ 32.0f,32.0f },
			Rect_New((Vec2){ 800.0f,0.0f },(Vec2){ 400.0f,100.0f }),
			RED,
			GREEN
		) 
	},sizeof(Button));
}

void Update(AlxWindow* w){
	Scene_Update(&scene,window.Strokes,GetMouse(),GetMouseBefore());

	Clear(BLACK);

	Scene_Render(WINDOW_STD_ARGS,&scene);
}

void Delete(AlxWindow* w){
	Scene_Free(&scene);
}

int main(){
    if(Create("Guis",2500,1200,1,1,Setup,Update,Delete))
        Start();
    return 0;
}