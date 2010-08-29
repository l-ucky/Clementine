/* This file is part of Clementine.

   Clementine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Clementine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ui/wiimotedevshortcutsconfig.h"
#include "ui_wiimotedevshortcutsconfig.h"
#include "ui/wiimotedevshortcutgrabber.h"

#include "wiimotedev/shortcuts.h"
#include "wiimotedev/consts.h"

WiimotedevShortcutsConfig::WiimotedevShortcutsConfig(QWidget* parent)
  : QWidget(parent),
    ui_(new Ui_WiimotedevShortcutsConfig)
{
  ui_->setupUi(this);
  ui_->list->header()->setResizeMode(QHeaderView::ResizeToContents);

  text_buttons_.insert(WIIMOTE_BTN_1, "Wiiremote 1");
  text_buttons_.insert(WIIMOTE_BTN_2, "Wiiremote 2");
  text_buttons_.insert(WIIMOTE_BTN_A, "Wiiremote A");
  text_buttons_.insert(WIIMOTE_BTN_B, "Wiiremote B");
  text_buttons_.insert(WIIMOTE_BTN_PLUS, "Wiiremote Plus");
  text_buttons_.insert(WIIMOTE_BTN_MINUS, "Wiiremote Minus");
  text_buttons_.insert(WIIMOTE_BTN_HOME, "Wiiremote Home");
  text_buttons_.insert(WIIMOTE_BTN_UP, "Wiiremote Up");
  text_buttons_.insert(WIIMOTE_BTN_DOWN, "Wiiremote Down");
  text_buttons_.insert(WIIMOTE_BTN_LEFT, "Wiiremote Left");
  text_buttons_.insert(WIIMOTE_BTN_RIGHT, "Wiiremote Right");
  text_buttons_.insert(WIIMOTE_BTN_SHIFT_UP, "Wiiremote Shift Up");
  text_buttons_.insert(WIIMOTE_BTN_SHIFT_DOWN, "Wiiremote Shift Down");
  text_buttons_.insert(WIIMOTE_BTN_SHIFT_LEFT, "Wiiremote Shift Left");
  text_buttons_.insert(WIIMOTE_BTN_SHIFT_RIGHT, "Wiiremote Shift Right");
  text_buttons_.insert(WIIMOTE_BTN_SHIFT_FORWARD, "Wiiremote Shift Forward");
  text_buttons_.insert(WIIMOTE_BTN_SHIFT_BACKWARD, "Wiiremote Shift Backward");
  text_buttons_.insert(WIIMOTE_BTN_TILT_FRONT, "Wiiremote Tilt Front");
  text_buttons_.insert(WIIMOTE_BTN_TILT_BACK, "Wiiremote Tilt Back");
  text_buttons_.insert(WIIMOTE_BTN_TILT_LEFT, "Wiiremote Tilt Left");
  text_buttons_.insert(WIIMOTE_BTN_TILT_RIGHT, "Wiiremote Tilt Right");
  text_buttons_.insert(NUNCHUK_BTN_Z, "Nunchuk Z");
  text_buttons_.insert(NUNCHUK_BTN_C, "Nunchuk B");
  text_buttons_.insert(NUNCHUK_BTN_STICK_UP, "Nunchuk Stick Up");
  text_buttons_.insert(NUNCHUK_BTN_STICK_DOWN, "Nunchuk Stick Down");
  text_buttons_.insert(NUNCHUK_BTN_STICK_LEFT, "Nunchuk Stick Left");
  text_buttons_.insert(NUNCHUK_BTN_STICK_RIGHT, "Nunchuk Stick Right");
  text_buttons_.insert(NUNCHUK_BTN_SHIFT_UP, "Nunchuk Shift Up");
  text_buttons_.insert(NUNCHUK_BTN_SHIFT_DOWN, "Nunchuk Shift Down");
  text_buttons_.insert(NUNCHUK_BTN_SHIFT_LEFT, "Nunchuk Shift Left");
  text_buttons_.insert(NUNCHUK_BTN_SHIFT_RIGHT, "Nunchuk Shift Right");
  text_buttons_.insert(NUNCHUK_BTN_SHIFT_FORWARD, "Nunchuk Shift Forward");
  text_buttons_.insert(NUNCHUK_BTN_SHIFT_BACKWARD, "Nunchuk Shift Backward");
  text_buttons_.insert(NUNCHUK_BTN_TILT_FRONT, "Nunchuk Tilt Front");
  text_buttons_.insert(NUNCHUK_BTN_TILT_BACK, "Nunchuk Tilt Back");
  text_buttons_.insert(NUNCHUK_BTN_TILT_LEFT, "Nunchuk Tilt Left");
  text_buttons_.insert(NUNCHUK_BTN_TILT_RIGHT, "Nunchuk Tilt Right");
  text_buttons_.insert(CLASSIC_BTN_X, "Classic X");
  text_buttons_.insert(CLASSIC_BTN_Y, "Classic Y");
  text_buttons_.insert(CLASSIC_BTN_A, "Classic A");
  text_buttons_.insert(CLASSIC_BTN_B, "Classic B");
  text_buttons_.insert(CLASSIC_BTN_L, "Classic L");
  text_buttons_.insert(CLASSIC_BTN_R, "Classic R");
  text_buttons_.insert(CLASSIC_BTN_ZL, "Classic ZL");
  text_buttons_.insert(CLASSIC_BTN_ZR, "Classic ZR");
  text_buttons_.insert(CLASSIC_BTN_MINUS, "Classic Minus");
  text_buttons_.insert(CLASSIC_BTN_PLUS, "Classic Plus");
  text_buttons_.insert(CLASSIC_BTN_HOME, "Classic Home");
  text_buttons_.insert(CLASSIC_BTN_UP, "Classic Up");
  text_buttons_.insert(CLASSIC_BTN_DOWN, "Classic Down");
  text_buttons_.insert(CLASSIC_BTN_LEFT, "Classic Left");
  text_buttons_.insert(CLASSIC_BTN_RIGHT, "Classic Right");
  text_buttons_.insert(CLASSIC_BTN_LSTICK_UP, "Classic Left-Stick Up");
  text_buttons_.insert(CLASSIC_BTN_LSTICK_DOWN, "Classic Left-Stick Down");
  text_buttons_.insert(CLASSIC_BTN_LSTICK_LEFT, "Classic Left-Stick Left");
  text_buttons_.insert(CLASSIC_BTN_LSTICK_RIGHT, "Classic Left-Stick Right");
  text_buttons_.insert(CLASSIC_BTN_RSTICK_UP, "Classic Right-Stick Up");
  text_buttons_.insert(CLASSIC_BTN_RSTICK_DOWN, "Classic Right-Stick Down");
  text_buttons_.insert(CLASSIC_BTN_RSTICK_LEFT, "Classic Right-Stick Left");
  text_buttons_.insert(CLASSIC_BTN_RSTICK_RIGHT, "Classic Right-Stick Right");
  text_buttons_.insert(WIIMOTE_BTN_SHIFT_SHAKE, "Wiiremote Shift Shake");
  text_buttons_.insert(NUNCHUK_BTN_SHIFT_SHAKE, "Nunchuk Shift Shake");

  text_actions_.insert(WiimotedevShortcuts::PlayerPlay, tr("Play"));
  text_actions_.insert(WiimotedevShortcuts::PlayerStop, tr("Stop"));
  text_actions_.insert(WiimotedevShortcuts::PlayerNextTrack, tr("Next track"));
  text_actions_.insert(WiimotedevShortcuts::PlayerPreviousTrack, tr("Previous track"));
  text_actions_.insert(WiimotedevShortcuts::PlayerMute, tr("Mute"));
  text_actions_.insert(WiimotedevShortcuts::PlayerPause, tr("Pause"));
  text_actions_.insert(WiimotedevShortcuts::PlayerTogglePause, tr("Play/Pause"));
  text_actions_.insert(WiimotedevShortcuts::PlayerSeekBackward, tr("Seek backward"));
  text_actions_.insert(WiimotedevShortcuts::PlayerSeekForward, tr("Seek forward"));
  text_actions_.insert(WiimotedevShortcuts::PlayerIncVolume, tr("Increase volume"));
  text_actions_.insert(WiimotedevShortcuts::PlayerDecVolume, tr("Decrease volume"));
  text_actions_.insert(WiimotedevShortcuts::PlayerShowOSD, tr("Show OSD"));


  settings_.beginGroup(WiimotedevShortcuts::kSettingsGroup);
  ui_->wiimotedev_enable->setChecked(settings_.value("enabled", true).toBool());
  ui_->wiimotedev_groupbox->setChecked(settings_.value("enabled", true).toBool());
  ui_->wiimotedev_active->setChecked(settings_.value("use_active_action", false).toBool());
  ui_->wiimotedev_focus->setChecked(settings_.value("only_when_focused", false).toBool());
  ui_->wiimotedev_notification->setChecked(settings_.value("use_notification", false).toBool());
  ui_->wiimotedev_device->setValue(settings_.value("device", 1).toUInt());
  settings_.endGroup();

  LoadSettings();

  connect(ui_->wiimotedev_enable, SIGNAL(clicked(bool)), this, SLOT(WiimotedevEnabledChecked(bool)));
  connect(ui_->list, SIGNAL(currentItemChanged(QTreeWidgetItem*, QTreeWidgetItem*)), SLOT(ItemClicked(QTreeWidgetItem*)));
  connect(ui_->wiimotedev_add_action, SIGNAL(clicked()), this, SLOT(AddAction()));
  connect(ui_->wiimotedev_delete_action, SIGNAL(clicked()), this, SLOT(DeleteAction()));
  connect(ui_->wiimotedev_reload, SIGNAL(clicked()), this , SLOT(DefaultSettings()));
}

void WiimotedevShortcutsConfig::LoadSettings(){
  settings_.beginGroup(WiimotedevShortcuts::kActionsGroup);
  settings_.sync();
  ui_->list->clear();

  quint64 fvalue, svalue;
  bool fvalid, svalid;

  foreach (const QString& str, settings_.allKeys()) {
    fvalue = str.toULongLong(&fvalid, 10);
    svalue = settings_.value(str, 0).toULongLong(&svalid);
    if (fvalid && svalid) {
      Shortcut s;
      s.object = new QTreeWidgetItem(ui_->list, QStringList() << GetReadableWiiremoteSequence(fvalue) << text_actions_[svalue]);
      s.button = fvalue;
      s.action = svalue;
      actions_ << s;
    }
    ui_->list->sortItems(1, Qt::AscendingOrder);
  }

  settings_.endGroup();
}

void WiimotedevShortcutsConfig::DefaultSettings()
{
  settings_.beginGroup(WiimotedevShortcuts::kActionsGroup);
  settings_.sync();
  settings_.remove("");
  settings_.setValue(QString::number(WIIMOTE_BTN_LEFT), WiimotedevShortcuts::PlayerPreviousTrack);
  settings_.setValue(QString::number(WIIMOTE_BTN_RIGHT), WiimotedevShortcuts::PlayerNextTrack);
  settings_.setValue(QString::number(WIIMOTE_BTN_SHIFT_LEFT), WiimotedevShortcuts::PlayerPreviousTrack);
  settings_.setValue(QString::number(WIIMOTE_BTN_SHIFT_RIGHT), WiimotedevShortcuts::PlayerNextTrack);
  settings_.setValue(QString::number(WIIMOTE_BTN_PLUS), WiimotedevShortcuts::PlayerIncVolume);
  settings_.setValue(QString::number(WIIMOTE_BTN_MINUS), WiimotedevShortcuts::PlayerDecVolume);
  settings_.setValue(QString::number(WIIMOTE_BTN_1), WiimotedevShortcuts::PlayerTogglePause);
  settings_.setValue(QString::number(WIIMOTE_BTN_2), WiimotedevShortcuts::PlayerShowOSD);
  settings_.endGroup();

  LoadSettings();
}

void WiimotedevShortcutsConfig::WiimotedevEnabledChecked(bool checked) {
  ui_->wiimotedev_groupbox->setEnabled(checked);
}

void WiimotedevShortcutsConfig::ItemClicked(QTreeWidgetItem* selected_item) {
  selected_item_ = selected_item;
}

QString WiimotedevShortcutsConfig::GetReadableWiiremoteSequence(quint64 value) {
  QMapIterator<quint64, QString> text(text_buttons_);

  QStringList list;
  while (text.hasNext()) {
    text.next();
    if ((text.key() & value) == text.key())
      list << text.value();
  }


  QString output;

  if (!list.isEmpty()) {
    for (int i = 0; i < (list.count() - 1); ++i)
      output += list.at(i) + " + ";
    output += list.last();
  }

  return output;
}

void WiimotedevShortcutsConfig::AddAction() {
  grabber = new WiimotedevShortcutGrabber(this, this);
  grabber->exec();
  delete grabber;
}

void WiimotedevShortcutsConfig::DeleteAction() {
  for (int i = 0; i < actions_.count(); ++i) {
    if (actions_.at(i).object == selected_item_) {
      delete selected_item_;
      actions_.removeAt(i);
      break;
    }
  }
}
